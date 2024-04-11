#include<bits/stdc++.h>



using namespace std;



#define MM 110000

#define ref 0x3f3f3f3f

typedef long long INT;

typedef pair <int ,int> pi;



map <pi ,int> mp, vis;

set <pi> s;

set <pi>::iterator it;

int n, dis[MM], id, cod[MM][2];

int dx[]={0,-1, 0,1, 1,-1,-1,1};

int dy[]={1, 0,-1,0,-1, 1,-1,1};



int main()

{

	int a,b,c,d,m,r,u,v;

//	freopen ("in.txt", "r", stdin);

	scanf ("%d%d%d%d", &a, &b, &c, &d);

	mp.clear(); s.clear();

	memset(dis, 0x3f, sizeof(dis));

	scanf ("%d", &m);   id=1;

	while (m--){

		scanf ("%d%d%d", &r, &u, &v);

		for(int i=u; i<=v; i++){

		 if(mp[pi(r, i)]!=0) continue;

		 cod[id][0]=r; cod[id][1]=i;

		 mp[pi(r, i)]=id;

		 if (r==a && i==b) dis[id]=0;

		 s.insert(pi(dis[id], id)); id++;

		}

	}

	for(int k=0; k<id-1; k++){

		r=s.begin()->second;

		s.erase(s.begin());

		u=cod[r][0]; v=cod[r][1];

		for(int i=0; i<8; i++){

			int x=u+dx[i], y=v+dy[i];

			if (!mp[pi(x, y)] || x<=0 || y<=0) continue;

			vis[pi(x, y)]=1;

			int  rr=mp[pi(x, y)];

			if(dis[rr]>dis[r]+1){

				s.erase(pi(dis[rr], rr));

				dis[rr]=dis[r]+1;

				s.insert(pi(dis[rr], rr));

			}

		}

	}

	if(dis[mp[pi(c, d)]]==ref || !mp[pi(c, d)]) puts("-1");

	else cout<<dis[mp[pi(c, d)]]<<endl;

	return 0;

}