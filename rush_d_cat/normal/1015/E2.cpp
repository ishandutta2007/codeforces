#include <iostream>
#include <vector>
using namespace std;
int n, m;

char s[1002][1002];
int u[1002][1002],d[1002][1002],l[1002][1002],r[1002][1002];
int len[1002][1002];

int R[1002][1002],C[1002][1002];
struct Nod {
    int x,y,d;
    Nod(){}
    Nod(int x_,int y_,int d_) {
        x=x_,y=y_,d=d_;
    }
};

vector<Nod> ans;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i-1][j]=='*') u[i][j]=u[i-1][j];
            else u[i][j]=i;

    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++)
            if(s[i+1][j]=='*') d[i][j]=d[i+1][j];
            else d[i][j]=i;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j-1]=='*') l[i][j]=l[i][j-1];
            else l[i][j]=j;

    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            if(s[i][j+1]=='*') r[i][j]=r[i][j+1];
            else r[i][j]=j;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            if(s[i][j]=='*') {
                len[i][j]=min(min(i-u[i][j], d[i][j]-i), min(j-l[i][j],r[i][j]-j));
                if (len[i][j]) {
                    ans.push_back(Nod(i,j,len[i][j]));
                    R[i][j-len[i][j]] += 1;
                    R[i][j+len[i][j]+1] += -1;
                    C[i-len[i][j]][j] += 1;
                    C[i+len[i][j]+1][j] += -1;
                }
            }
        }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            R[i][j] += R[i][j-1];
            C[i][j] += C[i-1][j];
            //printf("%d %d %d %d\n", i,j,R[i][j],C[i][j]);
            if (s[i][j] == '*' && (R[i][j]==0 && C[i][j] == 0)) return !printf("-1\n");
        }
    }
    printf("%d\n", ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].d);

}