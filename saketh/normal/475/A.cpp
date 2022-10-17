#include <iostream>
using namespace std;


int N, col, row;
string bus[6] = {"+------------------------+",
                 "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
                 "|#.#.#.#.#.#.#.#.#.#.#.|.|",
                 "|#.......................|",
                 "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
                 "+------------------------+"};
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        bus[row+1][2*col+1] = 'O';
        
        row++;
        if(col>0 && row==2) row++;
        if(row == 4){ row = 0; col++; }
    }

    for(int i=0; i<6; i++)
        cout << bus[i] << endl;
    return 0;
}