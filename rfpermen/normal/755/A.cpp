#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define MAX 10005
using namespace std;
ll n;
bool prima[2000001];
int main(){
	int X=2000001;
	memset(prima,true,sizeof prima);
	prima[0]=false; prima[1]=false;
	for( int i=2;i*i<= X;i++){
		if (prima[i]) {
			for( int j=i*i; j<=X; j += i) {
				prima[j]= false;
			}
		}
	}
	cin>>n;
	rep(i,1,1000){
		if(!prima[i*n+1]){
			cout<<i<<endl;
			return 0;
		}
	}
}