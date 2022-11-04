#include <cstdio>
#include <queue>
using namespace std;

int t, n;
priority_queue<int> a, b;

int diglog(int x){
    int res = 0;
    do{
        res++;
        x /= 10;
    } while (x);
    return res;
}

int main(){
    scanf("%d", &t);
    while(t--){
        a = priority_queue<int>();
        b = priority_queue<int>();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            int x;
            scanf("%d", &x);
            a.push(x);
        }
        for (int i = 1; i <= n; i++){
            int x;
            scanf("%d", &x);
            b.push(x);
        }
        int ans = 0;
        while(a.size() && b.size()){
            if(a.top() > b.top()){
                int x = a.top();
                a.pop();
                a.push(diglog(x));
                ans++;
            }
            else if(a.top() < b.top()){
                int x = b.top();
                b.pop();
                b.push(diglog(x));
                ans++;
            }
            else{
                a.pop();
                b.pop();
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}