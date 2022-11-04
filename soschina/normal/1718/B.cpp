#include <cstdio>
#include <queue>
using namespace std;
const int N = 1001;

int t, n, m, c[N];
long long f[N] = {0, 1, 1}, sum;
struct node{
    int cnt, id;
    node(int cnt, int id) : cnt(cnt), id(id){}
    bool operator<(const node &b) const{
        return cnt < b.cnt;
    }
};

priority_queue<node> q;

int main(){
	scanf("%d", &t);
    while(t--){
        while(q.size())
            q.pop();
        sum = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &c[i]);
            q.push(node(c[i], i));
            sum += c[i];
        }
        if(sum == 1){
            puts("YES");
            continue;
        }
        m = 2;
        sum -= 2;
        while(sum > 0){
            m++;
            f[m] = f[m - 1] + f[m - 2];
            sum -= f[m];
        }
        if(sum < 0){
            puts("NO");
            continue;
        }
        int last = 0;
        bool flag = true;
        for (int i = m; i; i--){
            if(q.empty()){
                flag = false;
                break;
            }
            node nd = q.top();
            q.pop();
            if(nd.id == last){
                if(q.empty()){
                    flag = false;
                    break;
                }
                node ano = q.top();
                q.pop();
                q.push(nd);
                nd = ano;
            }
            if(nd.cnt < f[i]){
                flag = false;
                break;
            }
            last = nd.id;
            nd.cnt -= f[i];
            if(nd.cnt)
                q.push(nd);
        }
        puts(flag ? "YES" : "NO");
    }
	return 0;
}