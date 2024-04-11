#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<iomanip>
using namespace std;

typedef long long ll;
const ll mod = 1e15;

map<int, int> M;

int n;
int num[200050];
ll sufsum[200050];
long double res = 0;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    sufsum[n] = 0;
    for(int i = n-1; i >= 0; i--) sufsum[i] = sufsum[i+1] + num[i];
    M[num[n-1]] ++;
    for(int i = n-2; i >= 0; i--) {
        if(!M.count(num[i])) M[num[i]] = 1;
        else M[num[i]] ++;

        int k1 = M[num[i]+1];
        int k2 = M[num[i]-1];
        //cout << M[2] << endl;
        long double add = (sufsum[i+1] - (ll)(n-1-i) * num[i]) - k1 + k2;
        res += add;
//        if(add > 0) {
//            if(add > mod) ans1 += add / mod;
//            ans2 += add % mod;
//            if(ans2 > mod) ans2 -= mod, ans1++;
//        }
//        else{
//        	ans1 += add / mod;
//        	ans2 += add % mod;
//        	if(ans2 < 0) ans2 += mod, ans1 --;
//		}


    }
    cout << fixed << setprecision(0) << res;

}