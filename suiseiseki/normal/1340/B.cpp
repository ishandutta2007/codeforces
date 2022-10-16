#include <bits/stdc++.h>
#define rep(i, l, r) for(long long i=l; i<=r ;i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
ll gcd(ll n,ll m){
	if(m==0){
		return n;
	}
	return gcd(m,n%m);
}
const int Maxn=2000;
bool enable[Maxn+5][Maxn+5];
string Number[10]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};
int val[10];
int dval[Maxn+5];
void Ini(){
	for(int i=0;i<=9;i++){
		for(int j=0;j<=6;j++){
			if(Number[i][j]=='1'){
				val[i]|=(1<<(7-j-1));
			}
		}
	}
}
void Input(int &n,int &k){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	string s;
    	cin>>s;
    	for(int j=0;j<=6;j++){
    		if(s[j]=='1'){
    			dval[i]|=(1<<(7-j-1));
			}
		}
	}
}
void solve(int n,int k){
	enable[n+1][0]=1;
	for(int i=n;i>0;i--){
        for(int j=9;j>=0;j--){
            if((val[j]&dval[i])==dval[i]){
				int diff=__builtin_popcount(val[j]^dval[i]);
                for(int kk=diff;kk<=k;kk++){
                	enable[i][kk]|=enable[i+1][kk-diff];
				}
            }
        }
	}
    if(!enable[1][k]){
        cout<<-1<<endl;
        return;
    }
    string ans="";
    int remain=k;
	for(int i=1;i<=n;i++){
		for(int j=9;j>=0;j--){
			if((val[j]&dval[i])==dval[i]){
				int diff=__builtin_popcount(val[j]^dval[i]);
				if(enable[i+1][remain-diff]){
					ans+=j+'0';
					remain-=diff;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
    Ini();
    int n,k;
    Input(n,k);
    solve(n,k);
    return 0;
}