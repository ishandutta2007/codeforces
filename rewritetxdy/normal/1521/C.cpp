#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e4+10;

int t,n,c[N];

inline int qmax(int x,int y){
	int ans,w = 0;
	cout<<'?'<<' '<<1<<' '<<x<<' '<<y<<' '<<n-1<<endl;
	cin>>ans;
	if(ans == n-1) {
		cout<<'?'<<' '<<1<<' '<<y<<' '<<x<<' '<<n-1<<endl;
		cin>>w;
	}
	return max(w,ans);
}

inline int qmin(int x,int y){
	int ans,w = n;
	cout<<'?'<<' '<<2<<' '<<x<<' '<<y<<' '<<1<<endl;
	cin>>ans;
	if(ans == 2) {
		cout<<'?'<<' '<<2<<' '<<y<<' '<<x<<' '<<1<<endl;
		cin>>w;
	}
	return min(w,ans);
}

int main()
{
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i+3 <= n;i += 3){
			int x = qmax(i+1,i+2) , y = qmin(i+1,i+2) , xx = qmax(i+2,i+3) , yy = qmin(i+2,i+3);
			if(x == xx) c[i+2] = x , c[i+1] = y , c[i+3] = yy;
			else if(x == yy) c[i+2] = x , c[i+1] = y , c[i+3] = xx;
			else if(y == xx) c[i+2] = y , c[i+1] = x , c[i+3] = yy;
			else c[i+2] = y , c[i+1] = x , c[i+3] = xx;
		}

		int i = n-3;
		int x = qmax(i+1,i+2) , y = qmin(i+1,i+2) , xx = qmax(i+2,i+3) , yy = qmin(i+2,i+3);
		if(x == xx) c[i+2] = x , c[i+1] = y , c[i+3] = yy;
		else if(x == yy) c[i+2] = x , c[i+1] = y , c[i+3] = xx;
		else if(y == xx) c[i+2] = y , c[i+1] = x , c[i+3] = yy;
		else c[i+2] = y , c[i+1] = x , c[i+3] = xx;

		cout<<'!'<<' ';
		for(int i=1;i <= n;i++) cout<<c[i]<<' ';
		cout<<endl;
	}
}