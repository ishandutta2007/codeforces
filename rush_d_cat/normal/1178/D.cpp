#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;
const int N = 1000 + 10;

bool isp(int x) {
    if(x==2)return 1;
    if(x<=1) return 0;
    for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}
int n;
int main() {
    cin>>n;

    //for(int n=5;n<=1000;n++){
        if(n==3){
            return !printf("3\n1 2\n2 3\n1 3\n");
        }
        if(n==4){
            return !printf("5\n1 2\n1 3\n2 3\n2 4\n3 4\n");
        }
        vector< pair<int,int> > v;
        for(int i=1;i<n;i++) v.push_back(make_pair(i,i+1));
        v.push_back(make_pair(n,1));

        int need;
        for(int i=n;;i++){
            if(isp(i)) {
                need=i-n;
                for(int x=1;x<=n && x+1<n-x; x++){
                    if(need) {
                        --need; v.push_back(make_pair(x,n-x));
                    }
                }
                break;
            }
        }
        printf("%d\n", v.size());
        for(auto p: v) {
            printf("%d %d\n", p.first,p.second);
        }
        //printf("n=%d, need=%d\n", n, need);
        //if(need) while(1); 
    //}
}