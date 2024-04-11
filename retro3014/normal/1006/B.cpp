#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

struct S{
    int x, y;
    bool operator <(const S &a)const{
        return x<a.x;
    }
};

int N, K;
vector<int> ans;
int ret;

int main(){
    cin>>N>>K;
    vector<S> v(N);
    for(int i=0; i<N; i++){
        scanf("%d", &v[i].x);
        v[i].y=i;
    }
    sort(all(v));
    ans.push_back(-1);
    for(int i=0; i<K; i++){
        ret+=v.back().x;
        ans.push_back(v.back().y);
        v.pop_back();
    }
    sort(all(ans));
    ans.pop_back();
    ans.push_back(N-1);
    cout<<ret<<endl;
    for(int i=1; i<ans.size(); i++){
        printf("%d ", ans[i]-ans[i-1]);
    }
    return 0;
}