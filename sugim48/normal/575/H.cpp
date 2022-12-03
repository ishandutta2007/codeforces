#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<unordered_map>
//#include<quadmath.h>
using namespace std;

#define MOD 1000000007
namespace math{
    long long int __gcd(long long int a, long long int b){
        if (a > b){
            swap(a, b);
        }
        while (a){
            swap(a, b);
            a %= b;
        }
        return b;
    }
    long long int lcm(long long int a, long long int b){
        long long int g = __gcd(a, b);
        a /= g;
        return a*b;
    }
    long long int ppow(long long int i, long long int j){
        long long int res = 1LL;
        while (j){
            if (j & 1LL){
                res *= i;
                res %= MOD;
            }
            i *= i;
            i %= MOD;
            j >>= 1LL;
        }
        return res;
    }
    long long int extgcd(long long int a, long long int b, long long int &x, long long int &y){
        long long int d = a;
        if (b != 0){
            d = extgcd(b, a%b, y, x);
            y -= (a / b)*x;
        }
        else{
            x = 1;
            y = 0;
        }
        return d;
    }
    long long int modinverse(long long int a, long long int b){   //a(mod b)
        long long int x, y;
        long long int d = extgcd(a, b, x, y);
        return (x%b + b) % b;
    }
    namespace matrix{
        vector<vector<long long int> > mul(vector<vector<long long int> > &a, vector<vector<long long int> > &b){
            vector<vector<long long int> > c(a.size(), vector<long long int>(b[0].size()));
            for (int i = 0; i < a.size(); i++){
                for (int j = 0; j < b.size(); j++){
                    for (int k = 0; k < b[0].size(); k++){
                        c[i][k] = (c[i][k] + a[i][j] * b[j][k]);
                        c[i][k] %= MOD;
                    }
                }
            }
            return c;
        }
        vector<vector<long long int> > ppow(vector<vector<long long int> > a, long long int n){
            vector<vector<long long int> > b = a;
            if (n == 1LL){
                return b;
            }
            n--;
            while (n){
                if ((n & 1LL)){
                    b = mul(b, a);
                }
                a = mul(a, a);
                n >>= 1LL;
            }
            return b;
        }
    }
    namespace fibonacci{
        /*
        index :1,2,3,4,5,6,
        number:1,1,2,3,5,8,
        */
        vector<vector<long long int> > mat;
        long long int get_fibonacci(long long int a){  //indexed from 1
            if (a == 0LL){
                return 1LL;
            }
            if (a == 1LL){
                return 1LL;
            }
            if (a == 2LL){
                return 1LL;
            }
            math::fibonacci::mat.clear();
            math::fibonacci::mat.assign(2, vector<long long int>(2, 0));
            math::fibonacci::mat[1][0] = 1LL;
            math::fibonacci::mat[0][1] = 1LL;
            math::fibonacci::mat[1][1] = 1LL;
            math::fibonacci::mat = math::matrix::ppow(mat, a - 2LL);
            long long int r = math::fibonacci::mat[0][1];
            r += mat[1][1];
            r %= MOD;
            return r;
        }
    }
    namespace factorial{
        vector<long long int> lo;
        vector<double> l2;
        void set_long(long long int b){
            if (lo.size()){
            }
            else{
                lo.push_back(1);
            }
            for (long long int i = lo.size(); i <= b; i++){
                lo.push_back(lo.back());
                lo.back() *= i;
                if (lo.back() >= MOD){
                    lo.back() %= MOD;
                }
            }
        }
        void set_log(long long int b){
            if (l2.size()){
            }
            else{
                l2.push_back(log(0.0));
            }
            for (long long int i = l2.size(); i <= b; i++){
                l2.push_back(l2.back());
                l2.back() += log((double)(i));
            }
        }
        long long int get_long(int b){
            if (lo.size() <= b){
                set_long(b);
            }
            return lo[b];
        }
        double get_log(int b){
            if (l2.size() <= b){
                set_log(b);
            }
            return l2[b];
        }
    }
    namespace combination{
        long long int simpleC(long long int a, long long int b){
            if (a < b){
                return 0;
            }
            if (a - b < b){
                b = a - b;
            }
            long long int u = 1LL;
            for (long long int j = a; j >= a - b + 1LL; j--){
                u *= j;
                if (u >= MOD){
                    u %= MOD;
                }
            }
            long long int s = 1LL;
            for (long long int i = 1LL; i <= b; i++){
                s *= i;
                if (s >= MOD){
                    s %= MOD;
                }
            }
            return (u*ppow(s, MOD - 2)) % MOD;
        }
        long long int C(long long int a, long long int b){
            if (a < b){
                return 0;
            }
            long long int u = math::factorial::get_long(a);
            long long int s = math::factorial::get_long(b)*math::factorial::get_long(a - b);
            u %= MOD;
            s %= MOD;
            return (u*ppow(s, MOD - 2)) % MOD;
        }
        double logC(int a, int b){
            double u = math::factorial::get_log(a);
            double s = math::factorial::get_log(b) + math::factorial::get_log(a - b);
            return u - s;
        }
        long long int H(long long int a, long long int b){
            return math::combination::C(a + b - 1LL, b);
        }
        long long int simpleH(long long int a, long long int b){
            return math::combination::simpleC(a + b - 1LL, b);
        }
    }
    namespace fraction{  //
        struct fr{
            long long int u;
            long long int s;
            fr(int u_ = 0, int s_ = 0){
                u = u_;
                s = s_;
            }
        };
        void y(fr &a){ //
            long long int g = __gcd(a.s, a.u);
            a.s /= g;
            a.u /= g;
        }
        fr mult(fr a, fr b){
            fr s;
            s.s = a.s*b.s;
            s.u = a.u*b.u;
            math::fraction::y(s);
            return s;
        }
        fr div(fr a, fr b){
            swap(b.s, b.u);
            return math::fraction::mult(a, b);
        }
        fr pluss(fr a, fr b){
            long long int k = math::lcm(a.s, b.s);
            a.u *= k / a.s;
            b.u *= k / b.s;
            a.s = b.s = k;
            a.u += b.u;
            math::fraction::y(a);
            return a;
        }
        fr minu(fr a, fr b){
            b = math::fraction::mult(b, fr(-1, 1));
            a = math::fraction::pluss(a, b);
            math::fraction::y(a);
            return a;
        }
    }
    namespace prime{
        vector<long long int> prime;
        vector<long long int> use;  //smallest divisor
        void init(int b){
            use.assign(b + 1, 0);
            prime.clear();
            prime.push_back(2);
            use[2] = 2;
            for (int i = 3; i < use.size(); i += 2){
                if (use[i] == 0LL){
                    prime.push_back(i);
                    use[i] = i;
                    for (int j = i * 2; j < use.size(); j += i){
                        use[j] = i;
                    }
                }
            }
        }
        vector<int> factorizetion(long long int num){
            vector<int> r;
            r.clear();
            for (int i = 0; i<prime.size() && prime[i] * prime[i] <= num; i++){
                while (num%prime[i] == 0LL){
                    r.push_back(prime[i]);
                    num /= prime[i];
                }
            }
            if (num > 1LL){
                r.push_back(num);
            }
            return r;
        }
        int size_of_factorization(long long int num){
            int cnt = 0;
            for (int i = 0; i<prime.size() && prime[i] * prime[i] <= num; i++){
                while (num%prime[i] == 0LL){
                    cnt++;
                    num /= prime[i];
                }
            }
            if (num > 1LL){
                cnt++;
            }
            return cnt;
        }
        long long int number_of_div(long long int num){
            long long int way = 1LL;
            long long int cnt = 0;
            for (int i = 0; i < prime.size() && prime[i] * prime[i] <= num; i++){
                cnt = 0;
                while (num%prime[i] == 0){
                    cnt++;
                    num /= prime[i];
                }
                way *= (cnt + 1LL);
            }
            if (num > 1LL){
                way *= 2LL;
            }
            return way;
        }
        bool isprime(int b){
            return binary_search(prime.begin(), prime.end(), b);
        }
        bool bruteprime(long long int b){
            for (long long int i = 2; i*i <= b; i++){
                if (b%i == 0LL){
                    return true;
                }
            }
            return false;
        }
    }
}
using namespace math;

int main(){
    int n;
    scanf("%d", &n);
    long long int ans = 1LL;
    long long int cur1 = 1LL;
    long long int cur2 = 0;
    for (int i = 1; i <= n*2; i++){
        ans += cur2;
        if (ans >= MOD){
            ans %= MOD;
        }
        cur1 *= 2LL;
        if (cur1 >= MOD){
            cur1 %= MOD;
        }
        ans += cur1;
        if (ans >= MOD){
            ans %= MOD;
        }
        if (i >= n){
            long long int way = combination::C(i - 1, n - 1);
            way *= 2LL;
            way %= MOD;
            cur2 += way;
            cur1 += MOD - way;
            if (cur2 >= MOD){
                cur2 %= MOD;
            }
            if (cur1 >= MOD){
                cur1 %= MOD;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}