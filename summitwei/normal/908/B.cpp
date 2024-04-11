#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    int N, M;
    cin >> N >> M;

    pii start;
    pii finish;
    vector<vector<char>> maze(N);
    for(int i=0; i<N; i++){
        maze[i].resize(M);
        for(int j=0; j<M; j++){
            cin >> maze[i][j];
            if(maze[i][j] == 'S'){
                start = make_pair(i, j);
            }
            if(maze[i][j] == 'E'){
                finish = make_pair(i, j);
            }
        }
    }

    string directions;
    cin >> directions;

    int count = 0;
    for(int i=0; i<24; i++){
        int up;
        int down;
        int left;
        int right;
        up = i/6;
        down = (i%6)/2; //will always get a number between 0-2
        if(down >= up){
            down++;
        }
        left = i%2;

        if(left >= up){
            left++;
        }
        if(left >= down){
            left++;
            if(up == left){
                left++;
            }
        }

        right = 6-up-down-left;


        //cout << up << down << left << right << "\n";

        pii currLoc = start;
        int j;
        for(j=0; j<directions.length(); j++){
            char dirAsChar = directions[j];
            int dir = dirAsChar-48;

            //cout << currLoc.first << " " << currLoc.second << " " << dir << "\n";

            if(dir == up){
                if(currLoc.first == 0 || maze[currLoc.first-1][currLoc.second] == '#'){
                    //cout << up << down << left << right << " crashed lolnoob\n";
                    break;
                }
                currLoc.first--;
                if(currLoc == finish){
                    count++;
                    //cout << up << down << left << right << " worked lolwow\n";
                    break;
                }
            } else if(dir == down){
                if(currLoc.first == N-1 || maze[currLoc.first+1][currLoc.second] == '#'){
                    //cout << up << down << left << right << " crashed lolnoob\n";
                    break;
                }
                currLoc.first++;
                if(currLoc == finish){
                    count++;
                    //cout << up << down << left << right << " worked lolwow\n";
                    break;
                }
            } else if(dir == left){
                if(currLoc.second == 0 || maze[currLoc.first][currLoc.second-1] == '#'){
                    //cout << up << down << left << right << " crashed lolnoob\n";
                    break;
                }
                currLoc.second--;
                if(currLoc == finish){
                    count++;
                    //cout << up << down << left << right << " worked lolwow\n";
                    break;
                }
            } else if(dir == right){
                if(currLoc.second == M-1 || maze[currLoc.first][currLoc.second+1] == '#'){
                    //cout << up << down << left << right << " crashed lolnoob\n";
                    break;
                }
                currLoc.second++;
                if(currLoc == finish){
                    count++;
                    //cout << up << down << left << right << " worked lolwow\n";
                    break;
                }
            }
        }
        /*if(j == directions.length()){
            cout << up << down << left << right << " failed lolgitgud\n";
        }*/
    }

    cout << count;
    return 0;
}