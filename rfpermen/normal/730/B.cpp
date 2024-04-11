#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
queue<int> maxi,mini;
char c;
int T,n,m,x,y;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n-1;i+=2){
			cout<<"? "<<i<<" "<<i+1<<endl;
			cin>>c;
			if(c=='>')maxi.push(i), mini.push(i+1);
			else maxi.push(i+1), mini.push(i);
		}
		if(n&1)maxi.push(n), mini.push(n);
		while(maxi.size()>1){
			x=maxi.front(); maxi.pop();
			y=maxi.front(); maxi.pop();
			cout<<"? "<<x<<" "<<y<<endl;
			cin>>c;
			if(c=='>')maxi.push(x);
			else maxi.push(y);
		}
		while(mini.size()>1){
			x=mini.front(); mini.pop();
			y=mini.front(); mini.pop();
			cout<<"? "<<x<<" "<<y<<endl;
			cin>>c;
			if(c=='>')mini.push(y);
			else mini.push(x);
		}
		//cout<<"? "<<n<<" "<<maxi.front()<<endl;
		cout<<"! "<<mini.front()<<" "<<maxi.front()<<endl;
		mini.pop(), maxi.pop();
	}
	return 0;
}