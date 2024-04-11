//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 1e3+20;
int arr[Maxn][Maxn];
bool b[Maxn][Maxn];
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0; i < k;i++){
		int x,y;
		cin >> x >> y;
		if(b[x][y])
			continue;
		b[x][y] = 1;
		arr[x-1][y-1]++;
		arr[x][y]++;
		arr[x-1][y]++;
		arr[x][y-1]++;
		for(int a = 0; a < 2;a++){
			for(int b = 0;b < 2;b++){
				if((x - a) && (y - b)){
					if(arr[x-a][y-b] == 4){
						cout << i+1 << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << 0 << endl;
	return 0;
}