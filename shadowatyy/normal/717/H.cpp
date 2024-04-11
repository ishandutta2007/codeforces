#include <bits/stdc++.h>
#define ll long long
#define VI vector<int>
#define pb push_back
using namespace std;

const int N = 1e6+7;
const int mod = 10007;

int n, e, ileTeam;

int team[N];
int teamChoice[N];

VI hate[N], teams[N];

VI losuTeam, losuPlayer, choices[N];

void wypisz(){
    for(int i = 1; i <= n; i++){
        for(auto it:teams[i]){
            if (team[it] == teamChoice[i]){
                cout << it << " ";
                break;
            }
        }
    }

    cout << endl;

    for(int i = 1; i <= ileTeam; i++){
        cout << team[i] +1  << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    srand(2137*69);

    cin >> n >> e;

    for(int i = 1; i <= e; i++){
        int a,b;
        cin >> a >> b;

        hate[a].pb(b);
        hate[b].pb(a);
    }

    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;

        for(int j = 1; j <= k; j++){
            int x;
            cin >> x;

            teams[i].pb(x);
            ileTeam = max(ileTeam, x);
        }
    }

    for(int i = 1; i <= ileTeam; i++){
        losuTeam.pb(i);
    }

    for(int i = 1; i <= n; i++){
        losuPlayer.pb(i);
    }

    while(1){
        random_shuffle(losuTeam.begin(), losuTeam.end());

        for(int i = 1; i <= ileTeam; i++){
            team[i] = 0;
        }

        for(int i = 0; i < ileTeam / 2; i++){
            team[losuTeam[i]] = 1;
        }

        for(int i = 1; i <= n; i++){
            choices[i].clear();

            for(auto it:teams[i]){
                choices[i].pb(team[it]);
            }

            sort(choices[i].begin(), choices[i].end());
            choices[i].erase(unique(choices[i].begin(), choices[i].end()), choices[i].end());

            teamChoice[i] = choices[i][rand()%choices[i].size()];
        }

        int wyn = 0;

        for(int i = 1; i <= n; i++){
            for(auto it:hate[i]){
                wyn += teamChoice[i] != teamChoice[it];
            }
        }

        wyn /= 2;

        random_shuffle(losuPlayer.begin(),losuPlayer.end());

        for(auto i:losuPlayer){
            if (wyn * 2 >= e){
                wypisz();
                return 0;
            }

            if (choices[i].size() > 1){
                int cou = 0;

                for(auto it:hate[i]){
                    cou += teamChoice[i] != teamChoice[it];
                }

                if (hate[i].size() - cou - cou > 0){
                    teamChoice[i] ^= 1;
                    wyn += hate[i].size() - cou - cou;
                }
            }
        }
    }

    return 0;
}