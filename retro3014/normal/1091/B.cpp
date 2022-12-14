#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define MAX_N 1000
set<pair<int, int>> s;
vector<pair<int, int>> xy, ab;
int N;
int x, y;
pair<int, int> ans;


int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d%d", &x, &y);
        s.insert(make_pair(x, y));
        xy.push_back(make_pair(x, y));
    }
    for(int i=1; i<=N; i++){
        scanf("%d%d", &x, &y);
        ab.push_back(make_pair(x, y));
    }
    for(int i=0; i<xy.size(); i++){
        ans.first = xy[i].first + ab[0].first;
        ans.second = xy[i].second + ab[0].second;
        bool tf=true;
        for(int j=0; j<ab.size(); j++){
            if(s.find(make_pair(ans.first-ab[j].first, ans.second-ab[j].second))==s.end()){
                tf=false;
                break;
            }
        }
        if(tf){
            printf("%d %d\n", ans.first, ans.second);
            break;
        }
    }
    return 0;
}