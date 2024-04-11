#include <iostream>
#include <vector>

using namespace std;
int n,m,k;
int c[2002];
vector<int> vec;
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++) {
        c[1]++; c[1+n]--;
        vec.push_back(1);
    }   

    for(int i=2;i<=n+m+1;i++){
        c[i] += c[i-1];
        if(c[i] == 0) {
            vec.push_back(i-1);
            c[i-1] ++; c[i] ++; c[i-1+n] --;
        }
        while(i <= n+m && c[i] < k) {
            vec.push_back(i);
            c[i] ++;
        }
    }
    printf("%d\n", vec.size());
    for(auto x: vec)
        printf("%d ", x);

}