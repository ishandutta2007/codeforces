#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

vector< pair< string, int > > all;

char buf[100];
vector< vector< int > > allId;
vector< int > p;

int
main()
{
    int n;
    scanf("%d", &n);
    all.reserve(2 * n);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", buf);
        all.push_back(make_pair(string(buf), i));
        scanf(" %s", buf);
        all.push_back(make_pair(string(buf), i));
    }
    sort(all.begin(), all.end());
    allId.clear();
    allId.resize(n);
    for (int i = 0; i < 2 * n; ++i) {
        allId[all[i].second].push_back(i);
    }
    int minId = -1;
    bool ok = true;
    for (int i = 0; i < n && ok; ++i) {
        int cur_id;
        scanf("%d", &cur_id);
        --cur_id;
        if (minId < allId[cur_id][0]) {
            minId = allId[cur_id][0];
        } else if (minId < allId[cur_id][1]) {
            minId = allId[cur_id][1];
        } else {
            ok = false;
        }
    }
    if (ok) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}