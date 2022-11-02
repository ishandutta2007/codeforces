#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 140000

struct Event{
    int rect;
    int val;
    bool yes;
};
//adding = false

bool comp(Event a, Event b){
    if(a.val != b.val) return a.val<b.val;
    return a.yes<b.yes;
}

Event events[MAX_N*2];
Event yEvents[MAX_N*2];
int used[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        events[i*2].rect = i;
        events[i*2].val = x1;
        events[i*2].yes = false;

        events[i*2+1].rect = i;
        events[i*2+1].val = x2;
        events[i*2+1].yes = true;

        yEvents[i*2].rect = i;
        yEvents[i*2].val = y1;
        yEvents[i*2].yes = false;

        yEvents[i*2+1].rect = i;
        yEvents[i*2+1].val = y2;
        yEvents[i*2+1].yes = true;
    }

    sort(events, events+2*n, comp);
    sort(yEvents, yEvents+2*n, comp);

    int amt = 0;
    for(int i=0; i<2*n; i++){
        if(!events[i].yes){
            amt++;
            used[events[i].rect] = true;
        } else{
            amt--;
            used[events[i].rect] = false;
        }

        if(amt >= n-1){
            //cout << "checking the x value of " << events[i].val << "\n";
            int real = 0;
            for(int j=0; j<2*n; j++){
                if(!used[yEvents[j].rect]) continue;

                //cout << "on yEvent " << j << " at val " << yEvents[j].val << "\n";
                
                if(!yEvents[j].yes){
                    real++;
                } else{
                    real--;
                }

                if(real == n-1){
                    cout << events[i].val << " " << yEvents[j].val << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "ABORT HELP\n";
    return 0;
}