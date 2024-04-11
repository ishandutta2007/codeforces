#include <bits/stdc++.h>

using namespace std;

const int k_M = 1e4 + 3;
const int k_D = 1e3 + 3;
const long long k_Max_Value = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static bool visited[k_M][k_D];
    static long long distance[k_M][k_D];
    static int d[k_M];
    static deque<pair<int, int>> q;

    int n, m, g, r;

    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
        cin >> d[i];
    cin >> g >> r;

    d[0] = 0;
    d[m + 1] = n;
    m += 2;
    sort(d, d + m);

    long long answer = k_Max_Value;

    q.push_front({0, 0});
    assert(distance[0][0] == 0);
    while(!q.empty()){
        auto [node, time] = q.front();
        q.pop_front();

        if(time == 0){
            int time_to_n = n - d[node];
            if(time_to_n <= g)
                answer = min(answer, distance[node][time] + time_to_n);
        }
        if(time == g){
            if(!visited[node][0]){
                distance[node][0] = distance[node][time] + (r + g);
                visited[node][0] = true;
                q.push_back({node, 0});
            }
            continue;
        }

        if(node != 0){
            int time_of_arrival = time + (d[node] - d[node - 1]);

            if(time_of_arrival <= g && !visited[node - 1][time_of_arrival]){
                visited[node - 1][time_of_arrival] = true;
                distance[node - 1][time_of_arrival] = distance[node][time];
                q.push_front({node - 1, time_of_arrival});
            }
        }
        if(node != m - 1){
            int time_of_arrival = time + (d[node + 1] - d[node]);

            if(time_of_arrival <= g && !visited[node + 1][time_of_arrival]){
                visited[node + 1][time_of_arrival] = true;
                distance[node + 1][time_of_arrival] = distance[node][time];
                q.push_front({node + 1, time_of_arrival});
            }
        }
    }

    if(answer == k_Max_Value)
        answer = -1;

    cout << answer << "\n";
}