#include <bits/stdc++.h>
using namespace std;

void good() {
    cout << "YES";
    exit(0);
}

int main() {
    int N; cin >> N;
    char grid[N][N];
    for (int i = 0; i < N; i++) {
        string row; cin >> row;
        for (int j = 0; j < N; j++) grid[i][j] = row[j];
    }

    string word = "theseus";
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < N-7) {
				string w = "";
				for (int k = 0; k < 7; k++) w += grid[i+k][j];
				if (w == word) good();
			}
			if (j < N-7) {
				string w = "";
				for (int k = 0; k < 7; k++) w += grid[i][j+k];
				if (w == word) good();
			}
			if (i < N-7 && j < N-7) {
				string w = "";
				for (int k = 0; k < 7; k++) w += grid[i+k][j+k];
				if (w == word) good();
			}
		}
    }
    cout << "NO";
}