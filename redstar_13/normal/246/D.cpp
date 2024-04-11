#include <bits/stdc++.h>



using namespace std;

#define MM 110000

int n, m, c[MM], deg[MM];

set<int>s[MM];



int main()

{

	int u, v;

//	freopen ("in.txt", "r", stdin);

	scanf ("%d%d", &n, &m);

	for (int i=0; i<n; i++) scanf("%d", c+i);

	while(m--){

		scanf("%d%d", &u, &v);

		u--; v--;

		if(c[u]==c[v]) continue;

		if(s[c[u]].find(c[v])==s[c[u]].end()){

		s[c[u]].insert(c[v]); deg[c[u]]++;

		}

		if(s[c[v]].find(c[u])==s[c[v]].end()){

		s[c[v]].insert(c[u]); deg[c[v]]++;

		}

	}

	sort(c, c+n);

	int ans=0, id=c[0];

	for (int i=0; i<n; i++){

		if(ans<deg[c[i]]) ans=deg[c[i]], id=c[i];

	}

	cout<<id<<endl;

}