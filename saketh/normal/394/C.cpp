#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <cstdio>
#include <set>
#include <iomanip>
#include <sstream>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(0);
    
    int N, M;
    std::cin >> N >> M;
    int dom[3] = {0, 0, 0};
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            int v;
            v = 0;
            std::cin >> v;
            v = v / 10 + v % 10;
            dom[v]++;
        }
    }

    std::vector<int> col[1100]; //list of dominoes in this column
    int row = 0; //which column are we in
    while (dom[1] + dom[2]) {
        if(dom[2]){
            col[row].push_back(11);
        }
        else {
            col[row].push_back(1);
            if (dom[1] > 1) col[row].push_back(10);
        }
        if (dom[2]) dom[2]--;
        else dom[1] = std::max(0, dom[1] - 2);
        row = (row + 1) % M;
    }

    for (int i = 0; i < M; i++) { // fill in 00s
        while(col[i].size() < N) {
            col[i].push_back(0);
        }
    //}
        if (col[i].size() > N) {
            for(int j = M-1; j>=0; j--) {
                if (col[j].size() < N) {
                    col[j].push_back(col[i].back());
                    col[i].pop_back();
                }
                if (col[i].size() == N) break;
            }
        }
}
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << col[j][i] / 10 << col[j][i] % 10 << " ";
        }
        std::cout << "\n";
    }
return 0;
}