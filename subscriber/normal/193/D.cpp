#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;

int n,a[333333],u[333333],w[333333],e[333333],ad[1999999],m1[1999999],k1[1999999],m2[1999999],k2[1999999];
long long ans=0;

void init(int p,int x,int y){
	if (x==y){
		m1[p]=0;
		k1[p]=1;
		k2[p]=0;
		return;		
	}
	init(p+p,x,(x+y)/2);
	init(p+p+1,(x+y)/2+1,y);
	k1[p]=k1[p+p]+k1[p+p+1];
}

void add(int p,int x,int y,int g,int v){
	if (g>y)return;
	if (g<=x){
		ad[p]+=v;
		m1[p]+=v;
		m2[p]+=v;
		return;
	}
	add(p+p,x,(x+y)/2,g,v);
	add(p+p+1,(x+y)/2+1,y,g,v);
	pair<int,int>q[4];
	q[0]=make_pair(m1[p+p],k1[p+p]);
	q[1]=make_pair(m2[p+p],k2[p+p]);
	q[2]=make_pair(m1[p+p+1],k1[p+p+1]);
	q[3]=make_pair(m2[p+p+1],k2[p+p+1]);
	for (int i=0;i<4;i++)for (int j=0;j<i;j++)if (q[i].first==q[j].first){
		q[j].second+=q[i].second;
		q[i].second=0;
	}
	sort(q,q+4);
	k1[p]=k2[p]=0;
	for (int i=0;i<4;i++)if (q[i].second>0){
		if (k1[p]==0)m1[p]=q[i].first,k1[p]=q[i].second;else if (k2[p]==0)m2[p]=q[i].first,k2[p]=q[i].second;
	}
	m1[p]+=ad[p];
	m2[p]+=ad[p];
}


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i],a[i]--,u[a[i]]=i;
//	for (int i=0;i<n;i++)a[i]=i+1,a[i]--,u[a[i]]=i;
	for (int i=0;i<n;i++){
		if (u[i]>0&&w[u[i]-1])e[i]--;else e[i]++;
		if (u[i]<n-1&&w[u[i]+1])e[i]--;else e[i]++;
		w[u[i]]=1;
	}
	init(1,0,n-1);
	for (int i=0;i<n;i++){
		add(1,0,n-1,i,e[i]);
	}
	for (int i=0;i<n;i++){
		if (m1[1]==2||m1[1]==4)ans+=k1[1];
		if (m2[1]==2||m2[1]==4)ans+=k2[1];
		ans-=i+1;
		if (u[i]>0&&w[u[i]-1])add(1,0,n-1,a[u[i]-1],2);
		if (u[i]<n-1&&w[u[i]+1])add(1,0,n-1,a[u[i]+1],2);
		add(1,0,n-1,i+1,-2);
		w[u[i]]=0;
	}
	cout << ans << endl;
	
}