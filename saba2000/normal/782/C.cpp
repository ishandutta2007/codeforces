#include<bits/stdc++.h>
using namespace std;
int n,a,b,k=0,p[200009],c[200009];
vector<int> v[200009];
void DFS(int x)
{set<int> S; int  C=1;
S.insert(c[x]);

for (int i=0; i<v[x].size(); i++)
if (c[v[x][i]]!=0) S.insert(c[v[x][i]]);
for (int i=0; i<v[x].size(); i++)
{while(S.find(C)!=S.end()) {C++;}
if (c[v[x][i]]==0) {c[v[x][i]]=C; S.insert(C);DFS(v[x][i]);}
}

}
//3
//2 3
//1 3
main()
//INETEEN
{cin>>n;
for (int i=0; i<n-1; i++)
{cin>>a>>b;
v[a].push_back(b);
v[b].push_back(a);
p[a]++; p[b]++;
k=max(k,p[a]+1);
k=max(k,p[b]+1);
}c[1]=1;
DFS(1);
cout<<k<<endl;
for (int i=1;i<=n; i++)
cout<<c[i]<<" ";

}

//1 3 7
//1 1 2