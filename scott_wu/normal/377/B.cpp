#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

const int MAXN = 210005;
struct student_info{  
    int b, c, ind;
    student_info(){}
};

student_info student[MAXN];
pair<int,int> a[MAXN];
int n, m, s, ans[MAXN];
priority_queue<student_info> q;

bool operator < (student_info left, student_info right)
{
    return left.c > right.c;
}
bool cmp(student_info A,student_info B){  
    return A.b < B.b;
}
bool check(int T, int i = m-1, int j = n-1){
    int mon = s;
    while (!q.empty()) q.pop();
    for (; i >= 0; ){
      while (j >= 0 && student[j].b >= a[i].first) q.push(student[j]), j --;
      if (q.empty()) return 0;
      student_info cho = q.top(); q.pop();
      if (mon >= cho.c){
           mon -= cho.c;
           for (int cnt = 0; i >= 0 && cnt < T; cnt ++, i --) 
               ans[a[i].second] = cho.ind;
       }else return 0;
    }return 1;
}
int main(){
    scanf("%d%d%d",&n, &m, &s);
    for (int i = 0; i < m; i ++) scanf("%d",&a[i].first), a[i].second = i;
    for (int i = 0; i < n; i ++) scanf("%d",&student[i].b);
    for (int i = 0; i < n; i ++) scanf("%d",&student[i].c);
    for (int i = 0; i < n; i ++) student[i].ind = i + 1;
    sort(a, a + m); sort(student, student + n, cmp);
    
    int l = 1, r = MAXN;
    if (!check(MAXN))
    {
        printf ("NO\n");
        return 0;
    }
    
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check (mid))
            r = mid;
        else
            l = mid + 1;
    }
          printf("YES\n");
          check(l);
          for (int i = 0; i < m; i ++) printf("%d ",ans[i]);
          printf("\n");
    return 0;
}