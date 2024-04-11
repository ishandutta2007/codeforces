#include <bits/stdc++.h>
 
using namespace std;
using nagai=long long;
#define sz(x) int((x).size())
 
 
const int N=300300;
int pref[N];
int preff[N];
int ans=0;
string s;
int ansl=-1,ansr=-1;
int n;
void calc(int l,int r){
	string s1=s;
	swap(s1[l],s1[r]);
	for(int i=0;i<n;++i)
		preff[i+1]=preff[i]+(s1[i]=='('?1:-1);
	int nmn=*min_element(preff,preff+n);
	int ans1=count(preff,preff+n,nmn);
	if(ans1>ans)
		ans=ans1,ansl=l,ansr=r;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>s;
	int c1=count(s.begin(),s.end(),'(');
	int c2=count(s.begin(),s.end(),')');
	if(c1!=c2){
		cout<<0<<'\n';
		cout<<1<<' '<<1<<'\n';
		return 0;
	}
	for(int i=0;i<n;++i)
		pref[i+1]=pref[i]+(s[i]=='('?1:-1);
	int mn=*min_element(pref,pref+n+1);
	vector<int>v;
	for(int i=0;i<n;++i)
		if(pref[i]==mn){
			v.push_back(i);
		}
	vector<array<int,3>>vv;
	for(int i=0;i<v.size();++i){
		int j=(i+1)%v.size();
		int ans=0;
		for(int k=v[i];k!=v[j];k=(k+1)%n)
			if(pref[k]==mn+1)
				ans+=1;
		vv.push_back({ans,v[i],v[j]});
	}
	sort(vv.begin(),vv.end());
	int sz=vv.size();
	for(int i=0;i<min(10,(int)vv.size());++i){
		calc(vv[i][1],(vv[i][2]+n-1)%n);
		calc(vv[sz-i-1][1],(vv[sz-i-1][2]+n-1)%n);
		calc((vv[i][1]+n-1)%n,vv[i][2]);
		calc((vv[sz-i-1][1]+n-1)%n,vv[sz-i-1][2]);
	}
	v.clear();
	vv.clear();
	for(int i=0;i<n;++i)
		if(pref[i]==mn+1){
			v.push_back(i);
		}
	for(int i=0;i<v.size();++i){
		int j=(i+1)%v.size();
		int ans=0;
		for(int k=v[i];k!=v[j];k=(k+1)%n)
			if(pref[k]==mn+2)
				ans+=1;
		vv.push_back({ans,v[i],v[j]});
	}
	sort(vv.begin(),vv.end());
	sz=vv.size();
	for(int i=0;i<min(10,(int)vv.size());++i){
		calc(vv[i][1],(vv[i][2]+n-1)%n);
		calc(vv[sz-i-1][1],(vv[sz-i-1][2]+n-1)%n);
		calc((vv[i][1]+n-1)%n,vv[i][2]);
		calc((vv[sz-i-1][1]+n-1)%n,vv[sz-i-1][2]);
	}
	v.clear();
	vv.clear();
	for(int i=0;i<n;++i)
		if(pref[i]==mn+2){
			v.push_back(i);
		}
	for(int i=0;i<v.size();++i){
		int j=(i+1)%v.size();
		int ans=0;
		for(int k=v[i];k!=v[j];k=(k+1)%n)
			if(pref[k]==mn+1)
				ans+=1;
		vv.push_back({ans,v[i],v[j]});
	}
	sort(vv.begin(),vv.end());
	sz=vv.size();
	for(int i=0;i<min(10,(int)vv.size());++i){
		calc(vv[i][1],(vv[i][2]+n-1)%n);
		calc(vv[sz-i-1][1],(vv[sz-i-1][2]+n-1)%n);
		calc((vv[i][1]+n-1)%n,vv[i][2]);
		calc((vv[sz-i-1][1]+n-1)%n,vv[sz-i-1][2]);
	}
	calc(0,0);
	cout<<ans<<'\n';
	cout<<ansl+1<<' '<<ansr+1<<'\n';
	return 0;
}