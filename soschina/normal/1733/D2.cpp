#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100100;

int T, n, x, y, s, t, cnt, head[N], nxt[N], to[N], c[N], w[N], eid;
void addedge(int u, int v, int cc, int ww){
    to[eid] = v;
    c[eid] = cc;
    w[eid] = ww;
    nxt[eid] = head[u];
    head[u] = eid++;
}

bool a[N];
char strs[N], strt[N];

const int INF = 0x3f3f3f3f;
int d[N], p[N], q[N], l, r;
bool inq[N];
bool spfa(int s, int t){
	memset(d + 1, 0x3f, sizeof(int) * (n + 2));
	d[s] = 0;
	l = r = 0;
	q[r++] = s;
	inq[s] = true;
	while(l != r){
		int &i = q[l++];
		l %= N;
		inq[i] = false;
		for(int e = head[i]; e; e = nxt[e])
            if(c[e] && d[i] + w[e] < d[to[e]]){
		    	d[to[e]] = d[i] + w[e];
		    	p[to[e]] = e;
		    	if(!inq[to[e]]){
		    		q[r++] = to[e];
		    		r %= N;
		    		inq[to[e]] = true;
		    	}
		    }
	}
	return d[t] != INF;
}
long long costflow(int s, int t){
    long long ans = (long long)(cnt / 2) * y;
    int ansflow = 0, anscost = 0;
    while(spfa(s, t)){
        int flow = 0x3f3f3f3f;
		for(int i = t; i != s; i = to[p[i] ^ 1])
			flow = min(flow, c[p[i]]);
		ansflow += flow;
		for(int i = t; i != s; i = to[p[i] ^ 1]){
			c[p[i]] -= flow;
			c[p[i] ^ 1] += flow;
			anscost += w[p[i]] * flow;
		}
        ans = min(ans, (long long)anscost * x + (long long)(cnt / 2 - ansflow) * y);
    }
    return ans;
}


int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%s%s", &n, &x, &y, strs + 1, strt + 1);
        cnt = 0;
        int pos1 = 0, pos2 = 0;
        for (int i = 1; i <= n; i++){
            a[i] = strs[i] != strt[i];
            cnt += a[i];
            if(a[i]){
                if(pos1)
                    pos2 = i;
                else
                    pos1 = i;
            }
        }
        if(cnt & 1){
            puts("-1");
            continue;
        }
        if(y <= x){
            if(cnt == 2 && pos1 + 1 == pos2)
                printf("%d\n", min(y * 2, x));
            else
                printf("%lld\n", (long long)(cnt >> 1) * y);
        }
        else{
            memset(head + 1, 0, sizeof(int) * (n + 2));
            eid = 2;
            s = n + 1, t = n + 2;
            int last = 0;
            bool side = 1;
            for (int i = 1; i <= n; i++){
                if(a[i]){
                    if(side){
                        addedge(s, i, 1, 0);
                        addedge(i, s, 0, 0);
                        if(last){
                            addedge(i, last, 1, i - last);
                            addedge(last, i, 0, last - i);
                        }
                    }
                    else{
                        addedge(i, t, 1, 0);
                        addedge(t, i, 0, 0);
                        addedge(last, i, 1, i - last);
                        addedge(i, last, 0, last - i);
                    }
                    last = i;
                    side ^= 1;
                }
            }
            printf("%lld\n", costflow(s, t));
        }
    }
    return 0;
}