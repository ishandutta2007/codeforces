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
ll n,k,x[500],y[500],tmp;
bool lol[505],lel[505];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	rep(i,1,k)cin>>x[i];
	rep(i,1,k-1){
	    tmp=(x[i]+y[x[i]])%n;
	    if(tmp==0)tmp=n;
		if(y[x[i]]==0){
			if(x[i]<x[i+1])y[x[i]]=x[i+1]-x[i] , lol[x[i+1]-x[i]]=1;
			else y[x[i]]=x[i+1]-x[i]+n, lol[x[i+1]-x[i]+n]=1;
		}
		else if(tmp!=x[i+1]){
			cout<<-1<<endl;
			return 0;
		}
		//cout<<"lala"<<endl;
	}
	rep(i,1,n){
		if(y[i]==0){
		    //cout<<"lala"<<endl;
			rep(j,1,n){
				if(lol[j]==0){
				    y[i]=j, lol[j]=1;
				    break;
				}
			}
		}
	}
	rep(i,1,n){
	    if(y[i]==0 || lel[y[i]]){
	        cout<<-1<<endl;
	        return 0;
	    }
	    lel[y[i]]=1;
	}
	rep(i,1,n){
	    cout<<y[i];
	    if(i<n)cout<<" ";
	    else cout<<endl;
	}
	return 0;
}