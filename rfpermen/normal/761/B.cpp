#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int a,b,x[10001],y[10001],X[10001],Y[10001];
int main() {
    cin>>a>>b;
	rep(i,a)cin>>x[i];
	rep(i,a)cin>>y[i];
	rep(i,a){
		if(i==a-1)X[i]=b+x[0]-x[i], Y[i]=b+y[0]-y[i];
		else X[i]=x[i+1]-x[i], Y[i]=y[i+1]-y[i];
	}
	//rep(i,a)cout<<X[i]<<" ";
	//cout<<endl;
	rep(i,a){
		rep(j,a){
			if(X[j]!=Y[j]){
				rep(k,a-1)swap(Y[0],Y[k+1]);
				//rep(k,a)cout<<Y[k]<<" ";
				//cout<<endl;
				break;
			}
			else if(X[j]==Y[j] && j==a-1){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
    return 0;
}