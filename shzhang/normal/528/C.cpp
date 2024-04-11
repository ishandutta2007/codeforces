#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <list>

using namespace std;

/*struct LL {
    int to;
    LL* prev; LL* next;
};

LL* head[100005];*/
/* to, edgeid */
list<pair<int, int> > graph[100005];
int nextedge = 1;
bool used[300005];
int degree[100005];

int n, m;

void insert_edge(int a, int b)
{
    graph[a].push_back(make_pair(b, nextedge));
    if (a != b) graph[b].push_back(make_pair(a, nextedge));
    degree[a]++; degree[b]++; nextedge++;
    //printf("added %d %d\n", a, b);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        insert_edge(a, b);
    }
    vector<int> odds;
    for (int i = 1; i <= n; i++) {
        if (degree[i] & 1) odds.push_back(i);
    }
    for (int i = 0; i < odds.size(); i += 2) {
        insert_edge(odds[i], odds[i+1]); m++;
    }
    if (m & 1) {
        insert_edge(1, 1); m++;
    }
    deque<int> tour;
    int remaining = m;
    tour.push_back(1);
    while (remaining) {
        while (!graph[tour.front()].empty() && used[graph[tour.front()].begin()->second]) {
            graph[tour.front()].erase(graph[tour.front()].begin());
        }
        while (graph[tour.front()].empty()) {
            tour.pop_front(); tour.push_back(tour.front());
            while (!graph[tour.front()].empty() && used[graph[tour.front()].begin()->second]) {
                graph[tour.front()].erase(graph[tour.front()].begin());
            }
        }
        int newnode = graph[tour.front()].begin()->first;
        int edgeid = graph[tour.front()].begin()->second;
        used[edgeid] = true;
        tour.push_front(newnode);
        remaining--;
    }
    vector<int> seq;
    while (!tour.empty()) {
        seq.push_back(tour.back()); tour.pop_back();
    }
    //for (int i = 0; i < seq.size(); i++) printf("%d ", seq[i]);
    //printf("\n");
    printf("%d\n", m);
    for (int i = 0; i + 1 < seq.size(); i++) {
        if (i & 1) {
            printf("%d %d\n", seq[i], seq[i+1]);
        } else {
            printf("%d %d\n", seq[i+1], seq[i]);
        }
    }
    return 0;
}