#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define pb push_back
#define cinn int n;scanf("%d", &n);
#define cinnm int n,m;cin>>n>>m;
#define cinnk int n,k;cin>>n>>k
#define vc vector
#define forin for(int i=0;i<n;++i)

int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

int lcm (int a, int b) {
	return a / gcd (a, b) * b;
}

int main(){
cinn
vc<string> A(n);
vc<string> B(n);
    forin{
        cin >> A[i] >> B[i];
    }
    string ans = "YES";
    string last;
    forin{
        int t;
        cin >> t;
        --t;
        if(i == 0) last = min(A[t], B[t]);
        string a = min(A[t], B[t]);
        string b = max(A[t], B[t]);
        if(last > b){
            ans = "NO";
            break;
        }else if(last > a){
            last = b;
        }else{
            last = a;
        }

    }
    cout << ans;
    return 0;
}