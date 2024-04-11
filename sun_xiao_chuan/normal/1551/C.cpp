#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sum,res;

struct sb{
	int a,b,c,d,e,f,su;
	bool operator<(const sb x)const{
		return f>x.f;
	}
}s[200500];

string sb;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		res=0;
		for(i=1;i<=n;i++){
			s[i].a=s[i].b=s[i].c=s[i].d=s[i].e=s[i].su=0;
			cin>>sb;
			for(auto j:sb){
				if(j=='a'){s[i].a++;}
				if(j=='b'){s[i].b++;}
				if(j=='c'){s[i].c++;}
				if(j=='d'){s[i].d++;}
				if(j=='e'){s[i].e++;}
				s[i].su++;
			}
		}
		
		for(i=1;i<=n;i++){
			s[i].f=s[i].a*2-s[i].su;
		}
		sort(s+1,s+n+1);
		k=0;
		s[n+1].f=-1145141919;
		for(i=1;i<=n+1;i++){
			if(s[i].f+k<=0){res=max(res,i-1);break;}k+=s[i].f;
		}
		
		for(i=1;i<=n;i++){
			s[i].f=s[i].b*2-s[i].su;
		}
		sort(s+1,s+n+1);
		k=0;
		s[n+1].f=-1145141919;
		for(i=1;i<=n+1;i++){
			if(s[i].f+k<=0){res=max(res,i-1);break;}k+=s[i].f;
		}
		
		for(i=1;i<=n;i++){
			s[i].f=s[i].c*2-s[i].su;
		}
		sort(s+1,s+n+1);
		k=0;
		s[n+1].f=-1145141919;
		for(i=1;i<=n+1;i++){
			if(s[i].f+k<=0){res=max(res,i-1);break;}k+=s[i].f;
		}
		
		for(i=1;i<=n;i++){
			s[i].f=s[i].d*2-s[i].su;
		}
		sort(s+1,s+n+1);
		k=0;
		s[n+1].f=-1145141919;
		for(i=1;i<=n+1;i++){
			if(s[i].f+k<=0){res=max(res,i-1);break;}k+=s[i].f;
		}
		
		for(i=1;i<=n;i++){
			s[i].f=s[i].e*2-s[i].su;
		}
		sort(s+1,s+n+1);
		k=0;
		s[n+1].f=-1145141919;
		for(i=1;i<=n+1;i++){
			if(s[i].f+k<=0){res=max(res,i-1);break;}k+=s[i].f;
		}
		cout<<res<<endl;
	}
}