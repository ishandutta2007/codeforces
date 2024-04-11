#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

bool col(P a, P b, P c){
    return 1LL * (a.second - b.second) * (a.first - c.first) -
                   1LL * (a.first - b.first) * (a.second - c.second) == 0;
}

int n;
P p[100050];
vector<P> arr;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%d", &p[i].first, &p[i].second);
    if(n <= 4) return !printf("YES");
    arr.push_back(p[0]);
    arr.push_back(p[1]);
    for(int i = 2; i < n; i++){
        if(!col(p[0],p[1],p[i])){arr.push_back(p[i]); break;}
    }
    if(arr.size() == 2) return !printf("YES");
    sort(arr.begin(), arr.end());
    do{
        vector<P> no;
        for(int i = 0; i < n; i++){
            if(!col(arr[0],arr[1],p[i])) no.push_back(p[i]);
        }
        bool good = true;
        for(int i = 2; i < no.size(); i++){
            if(!col(no[0],no[1],no[i])){good = false; break;}
        }
        if(good) return !printf("YES");
    }while(next_permutation(arr.begin(), arr.end()));
    return !printf("NO");
}