#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;
    int m = n;
    int k = 0;
    while(m){
        k++;
        m /= 10;
    }
    queue<P> que;
    que.push(P(n, k));
    int p[10];
    p[0] = 1;
    for(int i = 1; i < 10; i++) p[i] = p[i - 1] * 10;
    while(que.size()){
        P q = que.front();
        que.pop();
        int u = q.first;
        int b = q.second;
        int i;
        for(i = 1; i * i < u; i++){}
        if(i * i == u){
            cout << k - b << endl;
            return 0;
        }
        if(b == 1) continue;
        for(int j = 0; j < b - 1; j++){
            que.push(P(u / p[j + 1] * p[j] + u % p[j], b - 1));
        }
        if(u - u / p[b - 1] * p[b - 1] >= p[b - 2]) que.push(P(u % p[b - 1], b - 1));
    }
    cout << -1 << endl;
}