#include <queue>
#include <iostream>
using namespace std;

int C, E, S, L;
vector<pair<int, int> > edg[100005];
priority_queue<pair<int, int> > pq;
int dist[100005];

int main(){
    cin >> C >> E >> S;
    S--;
    
    for(int i=0; i<E; i++){
        int A, B, W;
        cin >> A >> B >> W;
        A--;
        B--;
        edg[A].push_back(make_pair(B, W));
        edg[B].push_back(make_pair(A, W));
    }
    
    cin >> L;
    
    for(int i=0; i<C; i++)
        dist[i] = -1;
    pq.push(make_pair(0, S));    

    while(!pq.empty()){
        int cos = -1 * pq.top().first;
        int loc = pq.top().second;
        pq.pop();
        if(dist[loc] != -1) continue;
        dist[loc] = cos;
        
        for(int i=0; i<edg[loc].size(); i++)
            if(dist[edg[loc][i].first] == -1)
                pq.push(make_pair(-1 * (cos + edg[loc][i].second), edg[loc][i].first));
    }
    
    int ans = 0;
    for(int i=0; i<C; i++)
        ans += dist[i] == L;
        
    int ans2 = 0;
    for(int i=0; i<C; i++)
        for(int j=0; j<edg[i].size(); j++){
            int loc1 = i;
            int loc2 = edg[i][j].first;
            int len = edg[i][j].second;
            
            int ilen1 = L - dist[loc1], jlen1 = len - ilen1;
            if( ilen1 > 0 && ilen1 < len && ilen1+dist[loc1] <= jlen1+dist[loc2])                 
                ans2++;
            
            int jlen2 = L - dist[loc2], ilen2 = len - jlen2;
            
            if( ilen2 == ilen1) continue;
            if( jlen2 > 0 && jlen2 < len && jlen2+dist[loc2] <= ilen2+dist[loc1]) 
                ans2++;
        }
    
    cout << ans + ans2/2 << endl;

    return 0;
}