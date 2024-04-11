#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>
#include<list>
#include<set>

using namespace std;
                   
int n,m,x,y,z,orr[1111],now[1333],sz[3133],d[3133],nor[1111],dd[1111];
string na[1111],ty[1111],nam[1111],typ[1111],g;
vector<string>v[3133];
map<string,int>M;
set<string>B;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> na[i] >> ty[i] >> x >> y >> z >> sz[i];
		M[na[i]]=i;
		if (ty[i][0]=='w')orr[i]=x;
		if (ty[i][0]=='a')orr[i]=y;
		if (ty[i][0]=='o')orr[i]=z;
		nor[i]=orr[i];
	}
	cin >> m;
	for (int i=0;i<m;i++){
		cin >> nam[i] >> typ[i] >> d[i] >> g;
		int o=M[g];
		v[o].push_back(nam[i]);
		if (ty[o][0]=='w'&&typ[i][0]=='g'||ty[o][0]=='a'&&typ[i][0]=='s'||ty[o][0]=='o'&&typ[i][0]=='p')nor[o]+=d[i];
	}
	int t=0;
	for (int i=0;i<n;i++)if (v[i].size()<sz[i])t=1;
	if (!t){
		int oo=-1,l=0;
		for (int i=0;i<n;i++)if (ty[i][0]=='w'&&nor[i]>oo)oo=nor[i],l=i;
		cout << na[l] << " " << v[l].size();
		for (int i=0;i<v[l].size();i++)cout << " " << v[l][i];
		puts("");
		oo=-1,l=0;
		for (int i=0;i<n;i++)if (ty[i][0]=='a'&&nor[i]>oo)oo=nor[i],l=i;
		cout << na[l] << " " << v[l].size();
		for (int i=0;i<v[l].size();i++)cout << " " << v[l][i];
		puts("");
		oo=-1,l=0;
		for (int i=0;i<n;i++)if (ty[i][0]=='o'&&nor[i]>oo)oo=nor[i],l=i;
		cout << na[l] << " " << v[l].size();
		for (int i=0;i<v[l].size();i++)cout << " " << v[l][i];
		puts("");
		return 0;
	}
	int oo=-1,l1=0,l2=0,l3=0;
	vector<pair<int,string> >uu1,uu2,uu3;
	for (int i=0;i<m;i++)if (typ[i][0]=='g')uu1.push_back(make_pair(d[i],nam[i]));
	if (uu1.size()){
	sort(uu1.rbegin(),uu1.rend());
	dd[0]=uu1[0].first;
	for (int i=1;i<uu1.size();i++)dd[i]=dd[i-1]+uu1[i].first;
	for (int i=0;i<n;i++)if (ty[i][0]=='w'&&orr[i]+dd[min(sz[i],(int)uu1.size())-1]>oo)oo=orr[i]+dd[min(sz[i],(int)uu1.size())-1],l1=i;
	}else for (int i=0;i<n;i++)if (ty[i][0]=='w'&&orr[i]>oo)oo=orr[i],l1=i;

	for (int i=0;i<m;i++)if (typ[i][0]=='s')uu2.push_back(make_pair(d[i],nam[i]));
	oo=-1;
	if (uu2.size()){
	sort(uu2.rbegin(),uu2.rend());
	dd[0]=uu2[0].first;
	for (int i=1;i<uu2.size();i++)dd[i]=dd[i-1]+uu2[i].first;
	for (int i=0;i<n;i++)if (ty[i][0]=='a'&&orr[i]+dd[min(sz[i],(int)uu2.size())-1]>oo)oo=orr[i]+dd[min(sz[i],(int)uu2.size())-1],l2=i;
	}else for (int i=0;i<n;i++)if (ty[i][0]=='a'&&orr[i]>oo)oo=orr[i],l2=i;

	for (int i=0;i<m;i++)if (typ[i][0]=='p')uu3.push_back(make_pair(d[i],nam[i]));
	oo=-1;
	if (uu3.size()){
	sort(uu3.rbegin(),uu3.rend());
	dd[0]=uu3[0].first;
	for (int i=1;i<uu3.size();i++)dd[i]=dd[i-1]+uu3[i].first;
	for (int i=0;i<n;i++)if (ty[i][0]=='o'&&orr[i]+dd[min(sz[i],(int)uu3.size())-1]>oo)oo=orr[i]+dd[min(sz[i],(int)uu3.size())-1],l3=i;
	}else for (int i=0;i<n;i++)if (ty[i][0]=='o'&&orr[i]>oo)oo=orr[i],l3=i;

	for (int i=min(sz[l1],(int)uu1.size());i<uu1.size();i++)B.insert(uu1[i].second);
	for (int i=min(sz[l2],(int)uu2.size());i<uu2.size();i++)B.insert(uu2[i].second);
	for (int i=min(sz[l3],(int)uu3.size());i<uu3.size();i++)B.insert(uu3[i].second);

	while (uu1.size()<sz[l1]){
		if (B.begin()==B.end())break;
		uu1.push_back(make_pair(0,*B.begin()));
		B.erase(B.begin());
	}

	while (uu2.size()<sz[l2]){
		if (B.begin()==B.end())break;
		uu2.push_back(make_pair(0,*B.begin()));
		B.erase(B.begin());
	}

	while (uu3.size()<sz[l3]){
		if (B.begin()==B.end())break;
		uu3.push_back(make_pair(0,*B.begin()));
		B.erase(B.begin());
	}

	cout << na[l1] << " " << min(sz[l1],(int)uu1.size());
	for (int i=0;i<min(sz[l1],(int)uu1.size());i++)cout << " " << uu1[i].second;
	puts("");

	cout << na[l2] << " " << min(sz[l2],(int)uu2.size());
	for (int i=0;i<min(sz[l2],(int)uu2.size());i++)cout << " " << uu2[i].second;
	puts("");

	cout << na[l3] << " " << min(sz[l3],(int)uu3.size());
	for (int i=0;i<min(sz[l3],(int)uu3.size());i++)cout << " " << uu3[i].second;
	puts("");

	return 0;

}