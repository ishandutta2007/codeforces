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
bool cek[100000],prima[100];
int cnt,guess,ans,last;
string s;
int main(){
	ans=1;
	prima[1]=1;
	prima[2]=1;
	prima[3]=1;
	prima[5]=1;
	prima[7]=1;
	prima[11]=1;
	prima[13]=1;
	prima[17]=1;
	prima[19]=1;
	prima[23]=1;
	prima[29]=1;
	prima[31]=1;
	prima[37]=1;
	prima[41]=1;
	prima[43]=1;
	prima[47]=1;
	prima[53]=1;
	prima[59]=1;
	prima[61]=1;
	prima[67]=1;
	prima[71]=1;
	prima[73]=1;
	prima[29]=1;
	prima[83]=1;
	prima[89]=1;
	prima[97]=1;
	last=2;
	while(cnt<21){
		cnt++;
		while(last<=60){
			if(prima[last] || cek[last]){
				cout<<last<<endl;
				cin>>s;
				if(s=="yes")ans*=last, cek[last*last]=1;
			}
			last++;
		}
	}
	if(prima[ans] && ans<100)cout<<"prime"<<endl;
	else cout<<"composite"<<endl;
	return 0;
}