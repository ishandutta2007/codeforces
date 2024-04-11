#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

int q;
char c;
long long x;
set<long long> now;
map<long long, int> mp;
map<long long, set<int>> missing;
map<long long, vector<long long>> rem;

int main(){
	scanf("%d", &q);
    while(q--){
        scanf(" %c%lld\n", &c, &x);
        switch(c){
            case '+':
                for(long long val : rem[x])
                    missing[val].erase(x / val);
                now.insert(x);
                break;
            case '-':
                for(long long val : rem[x])
                    missing[val].insert(x / val);
                now.erase(x);
                break;
            case '?':
                if(missing[x].empty()){
                    while(now.find((mp[x] + 1) * x) != now.end()){
                        rem[(mp[x] + 1) * x].push_back(x);
                        mp[x]++;
                    }
                    printf("%lld\n", x * (mp[x] + 1));
                }
                else
                    printf("%lld\n", x * *missing[x].begin());
        }
    }
	return 0;
}