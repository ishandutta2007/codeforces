#include <cstdio>
#include <vector>
using namespace std;

const int MAXD = 20000;
const int MAXB = 4000;

int N, P, Q, ans[MAXD+5], back[MAXB+5][MAXB+5], forw[MAXB+5][MAXB+5];
vector<pair<int, int> > que[MAXD+5], itm[MAXD+5];

void apply(int d, int m[][MAXB+5], int *i){
    for(auto p : itm[d]){
        for(int c=1; c<=MAXB; c++){
            m[*i][c] = max(m[*i][c-1], m[*i-1][c]);
            if(c>=p.first) m[*i][c] = max(m[*i][c], p.second + m[*i-1][c-p.first]);
        }
        (*i)++;
    }
}

void calc(int sd){
    int i=1;
    for(int d = sd; d > max(0, sd-P); d--)
        apply(d, back, &i);
   
    for(int d = sd+1, j=1; d < min(MAXD+1, sd+P); d++)
        apply(d, forw, &j);

    int j=0; i--;
    for(int d = sd; d < min(MAXD+1, sd+P); d++){
        for(auto p : que[d])
            for(int bc = 0; bc <= p.first; bc++)
                ans[p.second] = max(ans[p.second], back[i][bc] + forw[j][p.first-bc]);
        if(d-P+1>0) i -= itm[d-P+1].size();
        if(d+1<=MAXD) j += itm[d+1].size();
    }
}

int main(){
    scanf("%d%d", &N, &P);
    for(int i=0, c, h, d; i<N; i++){
        scanf("%d%d%d", &c, &h, &d);
        itm[d].emplace_back(c, h);
    }

    scanf("%d", &Q);
    for(int i=0, d, b; i<Q; i++){
        scanf("%d%d", &d, &b);
        que[d].emplace_back(b, i);
    }

    for(int d=1; d<=MAXD; d+=P)
        calc(d);

    for(int i=0; i<Q; i++)
        printf("%d\n", ans[i]);
    return 0;
}