#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int k;
int cnt = 1;
vector<P> edge;

void genr(int a, int b){
    for(int i = a; i <= b; i++){
        for(int j = i+1; j <= b; j++){
            edge.push_back(P(i,j));
        }
    }
}

void gen(){
    for(int i = cnt+1; i <= cnt+k-1; i++) edge.push_back(P(i,cnt));
    int i = 0;
    while((i*(k-1) + (k-1-i)) % k != 0) i++;
    int old = cnt; cnt += k-1;
    for(int j = 0; j < i; j++){
        for(int t = 0; t < k-1; t++){
            edge.push_back(P(++cnt, old+1+j));
        }
    }
    int l = old+1+i, r = cnt;
    for(int j = l; j <= r; j += k) genr(j, j+k-1);
    cnt = r;
}

void com(){
    gen();
    edge.push_back(P(1,++cnt));
    gen();

}


int main(){
    cin >> k;
    if(k % 2 == 0) return !printf("NO");
    com();
    cout << "YES" << endl;
    cout << cnt << " " << edge.size() << endl;
    for(int i = 0; i < edge.size(); i++){
        cout << edge[i].first << " " << edge[i].second << endl;
    }
}