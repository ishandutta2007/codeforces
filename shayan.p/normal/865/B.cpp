#include<bits/stdc++.h>
#define ll long long
#define PB push_back
#define MP make_pair
#define pll pair<ll,ll>

//#define cin fin

using namespace std;

//ifstream fin ("my code.txt");

ll saghf(ll a,ll b)
{
	if(a%b==0) return a/b;
	return (a/b)+1;
}
int main()
{
	ll n,S;cin>>n>>S;
	ll sum=0,A=0,B=0,last=-1;deque<pll> d;ll s[n],a[n],b[n];
	for(ll i=0;i<n;i++)
	{
	cin>>s[i]>>a[i]>>b[i];
	d.PB(MP(a[i]-b[i],i));
	sum+=s[i];
	((a[i]>b[i])?A:B)+=s[i];
	}
	sort(d.begin(),d.end(),greater<pll>());
	ll pit=saghf(sum,S),fix1=A/S,fix2=B/S,ezafi=(pit*S)-sum;
	ll Ans1=0,Ans2=0;
	ll slice=fix1*S;
	while(slice>0)
	{
		ll id=d[0].second;
		ll w=s[id];
		ll kam=min(slice,w);
		Ans1+=kam*a[id];
		slice-=kam;
		if(w==kam)
		d.pop_front();
		else
		s[id]-=kam;
	}
	slice=fix2*S;
	while(slice>0)
	{
		ll id=d[d.size()-1].second;
		ll w=s[id];
		ll kam=min(slice,w);
		Ans1+=kam*b[id];
		slice-=kam;
		if(w==kam)
		d.pop_back();
		else
		s[id]-=kam;
	}
	for(ll i=0;i<=pit-fix1-fix2;i++) // i ta type 1
	{
		ll t1=i*S,t2=(pit-fix1-fix2-i)*S;
		for(ll j=0;j<=ezafi;j++)
		{
			ll ans=0,T1=t1-j,T2=t2-(ezafi-j);
			if(T1<0||T2<0)
			continue;
			for(ll k=0;k<d.size();k++) //calculates for T1 va T2
			{
			ll w=s[d[k].second];
			ll kam1=min(T1,w);
			ans+=kam1*a[d[k].second];
			T1-=kam1;
			w-=kam1;
			ll kam2=min(T2,w);
			ans+=kam2*b[d[k].second];
			T2-=kam2;
			w-=kam2;
			}
			Ans2=max(Ans2,ans);
		}
	}
	cout<<Ans1+Ans2;
}