#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, M;
int ans;
int SR, SC;
int L, R;
bool visit[2020][2020];

struct Queue{
    int left, right;
    int x, y;

    Queue(){}
    Queue(int l, int r, int x, int y):
        left(l), right(r), x(x), y(y){}

    bool operator<(const Queue &r)const{
        return (left+right) > (r.left+r.right);
    }
};

priority_queue<Queue> Q;

int main(){
    char ch;
    scanf("%d %d", &N, &M);
    scanf("%d %d", &SR, &SC);
    scanf("%d %d", &L, &R);
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            scanf(" %c", &ch);
            if (ch == '*') visit[i][j] = true;
        }
    }

    Q.push(Queue(0, 0, SR, SC));
    while(!Q.empty()){
        Queue T = Q.top();
        Q.pop();
        if (visit[T.x][T.y]) continue;
        ans++;
        visit[T.x][T.y] = true;
        if (T.x > 1) Q.push(Queue(T.left, T.right, T.x-1, T.y));
        if (T.x < N) Q.push(Queue(T.left, T.right, T.x+1, T.y));
        if (T.y > 1 && T.left < L) Q.push(Queue(T.left+1, T.right, T.x, T.y-1));
        if (T.y < M && T.right < R) Q.push(Queue(T.left, T.right+1, T.x, T.y+1));
    }
    printf("%d", ans);
    return 0;
}