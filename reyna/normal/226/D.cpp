//In the name of God
#include <iostream>
#include <vector>
using namespace std;
const int Maxn = 102;
int row[Maxn],col[Maxn];
int mat[Maxn][Maxn];
int markR[Maxn],markC[Maxn];
vector<int> ansR;
vector<int> ansC;
int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n;i++)
		for(int j = 0; j < m;j++){
			cin >> mat[i][j];
			row[i]+=mat[i][j];
			col[j]+=mat[i][j];
		}
	bool f = 1;
	while(f){
		f = 0;
		for(int i = 0; i < n;i++){
			if(row[i] < 0){
				ansR.push_back(i+1);
				for(int j = 0; j < m;j++){
					row[i] -= 2 * mat[i][j];
					col[j] -= 2 * mat[i][j];
					mat[i][j] *= -1;
				}
				f = 1;
				break;
			}
		}
		if(f)
			continue;
		for(int j = 0; j < m;j++){
			if(col[j] < 0){
				ansC.push_back(j+1);
				for(int i = 0; i < n;i++){
					row[i] -= 2 * mat[i][j];
					col[j] -= 2 * mat[i][j];
					mat[i][j] *= -1;
				}
				f = 1;
				break;
			}
		}
	}
	int R = 0;
	int C = 0;
	for(int i = 0; i < ansR.size();i++){
		R++;
		if(markR[ansR[i]] % 2)
			R-=2;
		markR[ansR[i]]++;
	}
	cout << R << ' ';
	for(int i = 0; i < ansR.size();i++)
		if(markR[ansR[i]] % 2){
			markR[ansR[i]]--;
			cout << ansR[i] << ' ';
		}
	for(int i = 0; i < ansC.size();i++){
		C++;
		if(markC[ansC[i]] % 2)
			C-=2;
		markC[ansC[i]]++;
	}
	cout << endl;
	cout << C << ' ';
	for(int i = 0; i < ansC.size();i++)
		if(markC[ansC[i]] % 2){
			markC[ansC[i]]--;
			cout << ansC[i] << ' ';
		}
	cout << endl;
	return 0;
}