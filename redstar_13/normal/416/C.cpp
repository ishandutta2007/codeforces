#include <bits/stdc++.h>



using namespace std;

#define MM 1100



struct visitor{

	int p, c;

	int num;

}req[MM];

int n, m, id[MM], vis[MM], ans[MM][2];

int cnt, tot, t[MM];



bool cm(visitor x, visitor y){

	return x.p<y.p;

}

bool cmp(int x, int y) {return t[x]<t[y];}

int main()

{

//	freopen ("in.txt", "r", stdin);

	scanf ("%d", &n);

	for (int i=0; i<n; i++) scanf ("%d%d", &req[i].p, &req[i].c), req[i].num=i;

	sort (req, req+n, cm);

	

	scanf ("%d", &m);

	for (int i=0; i<m; i++) scanf ("%d", t+i), id[i]=i;

	sort (id, id+m, cmp);

	int M=0;

	for (int i=0; i<m; i++){

		int mx=0, idx=-1;

		for (int j=0; j<n; j++){

			if (vis[req[j].num]) continue;

			if (req[j].p<=t[id[i]] && req[j].c>=mx){

				mx=req[j].c, idx=req[j].num;

			}

		}

		if (idx==-1) continue;

		vis[idx]=1;

		tot+=mx;

		ans[cnt][0]=idx; ans[cnt++][1]=id[i];

		M++;

	}

	cout<<M<<" "<<tot<<endl;

	for (int i=0; i<cnt; i++){

		printf("%d %d\n", ans[i][0]+1, ans[i][1]+1);

	}

	return 0;

}