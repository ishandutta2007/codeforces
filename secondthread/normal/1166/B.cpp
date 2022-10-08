#include <bits/stdc++.h>

using namespace std;
char board[5][5];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	char vow[5]={'a', 'e', 'i', 'o', 'u'};
	for (int i=0; i<5; i++)
		for (int j=0; j<5; j++) {
			board[i][j]=vow[(i+j)%5];
		}
	for (int div=5; div*5<=n; div++) {
		if (n%div==0) {
			int height=n/div;
			for (int i=0; i<n; i++) {
				int x=i%height;
				int y=i/height;
				x%=5;
				y%=5;
				if (x<5&&y<5)
					cout<<board[x][y];
				else
					cout<<'z';
			}
			cout<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	
	return 0;
}