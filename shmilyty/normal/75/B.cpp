#include<bits/stdc++.h>
using namespace std;
int n;
string mn;
map<string,int> a;
vector<pair<string,int> >V;
bool Less(const pair <string, int> &a, const pair <string, int> &b)
{
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}
int main()
{
	string s,b,c,act;
	cin>>mn>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b>>act;
		if(act!="likes")
			cin>>s;
		cin>>c;
		c=c.substr(0,c.size()-2);
		cin>>s;
		if (b!= mn &&a.find(b) ==a.end()) 
			a[b] = 0;
        if (c!= mn &&a.find(c) ==a.end()) 
			a[c] = 0;
        if (c== mn) 
			swap(b, c);
        if (b== mn)
            if (act == "posted") 
				a[c] += 15;
        	else 
				if (act == "commented")
					a[c] += 10;
            else 
				if (act == "likes")
					a[c] += 5;
	}
	for(map<string,int>::iterator it=a.begin();it!=a.end();it++)
		V.push_back(make_pair(it->first,it->second));
	sort(V.begin(),V.end(),Less);
	for(int i=0;i<V.size();i++)
		cout<<V[i].first<<endl;
	return 0;
}