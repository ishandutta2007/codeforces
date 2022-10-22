#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m , C[N];
pair<int , char> a[N];
char str[N];
void work() {
    /* //int T = 500;
       /*while (1) {
        int cnt = 0;
        n = rand() % 10 + 1;
        set<char> H;
        memset(C , 0 , sizeof(C));
        /*for (int i = 0 ; i < n ; ++ i) {
            str[i] = rand() % 3 + 'a';
            H.insert(str[i]);
            C[str[i] - 'a'] += 2;
            str[n + n - i - 1] = str[i];
            }
        scanf("%s" , str);
        n = strlen(str);
        int D = 0;
        for (int i = 0 ; i < 3 ; ++ i)
            D = __gcd(D , C[i]);
        //if (H.size() == 1) continue;
        // n += n , str[n] = 0;
        // scanf("%s" , str);
        for (int i = 0 ; i < n ; ++ i) {
            rotate(str , str + 1 , str + n);
            bool flag = 1;
            for (int j = 0 ; j < n / 2 ; ++ j)
                if (str[j] != str[n - j - 1]) {
                    flag = 0;
                    break;
                }
            cnt += flag;
        }
        if (1) {
            printf("%s " , str);
            cout << cnt << endl;
            // assert(D == cnt);
        }
    }
    return;*/
    
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i].first);
        a[i].second = 'a' + i;
        m += a[i].first;
    }
    if (n == 1) {
        printf("%d\n" , m);
        for (int k = 0 ; k < n ; ++ k)
            for (int l = 0 ; l < a[k].first ; ++ l)
                putchar('a' + k);
        puts("");
        return;
    }
    int odd = -1;
    for (int i = 0 ; i < n ; ++ i) {
        if (a[i].first % 2 == 1) {
            if (~odd) {
                puts("0");
                for (int k = 0 ; k < n ; ++ k)
                    for (int l = 0 ; l < a[k].first ; ++ l)
                        putchar('a' + k);
                puts("");
                return;
            } else {
                odd = i;
            }
        }
    }
    
    int D = 0;
    for (int i = 0 ; i < n ; ++ i)
        D = __gcd(a[i].first , D);
    if (~odd) {
        
        odd = -1;
        for (int i = 0 ; i < n ; ++ i) {
            if ((a[i].first / D) % 2 == 1) {
                if (~odd) {                    
                    puts("1");
                    string S;
                    for (int i = 0 ; i < n ; ++ i)
                        for (int j = 0 ; j < a[i].first / 2 ; ++ j)
                            S += a[i].second;
                    printf("%s%c" , S.c_str() , 'a' + odd);
                    reverse(S.begin() , S.end());
                    printf("%s%c" , S.c_str() , '\n');
                    return;
                } else {
                    odd = i;
                }
            }
        }
        printf("%d\n" , D);
        for (int i = 0 ; i < n ; ++ i)
            a[i].first /= D;        
        string S , T;
        for (int i = 0 ; i < n ; ++ i)
            for (int j = 0 ; j < a[i].first / 2 ; ++ j)
                S += a[i].second;
        T += S;
        T += a[odd].second;
        reverse(S.begin() , S.end());
        T += S;
        for (int i = 0 ; i < D; ++ i) {
            printf("%s" , T.c_str());
        }
        return;
    }
    printf("%d\n" , D);
    string S;
    for (int i = 0 ; i < n ; ++ i)
        for (int j = 0 ; j < a[i].first / D ; ++ j)
            S += a[i].second;
    string T = S;
    reverse(S.begin() , S.end());
    
    for (int i = 0 ; i < D; ++ i) {
        if (i & 1)
            printf("%s" , S.c_str());
        else
            printf("%s" , T.c_str());
    }
    puts("");
}

int main() {    
    work();
    return 0;
}