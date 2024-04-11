#include<cstdio>
#include<algorithm>
using namespace std;

int nums[100005];
int numsSorted[100005];
int n;
bool used[100005];

int height;
int len;

int binarySearchIndex(int a) {
    //printf("searching for %d...\n", a);
    int lower = 0;
    int upper = n-1;
    int mid = (n-1)/2;
    while(numsSorted[mid] != a) {
        if(numsSorted[mid] > a) {
            upper = mid - 1;
            mid = (lower + upper) / 2;
        } else {
            lower = mid + 1;
            mid = (lower + upper) / 2;
        }
    }
    return mid;
}

int main() {
	height = 0;
    scanf("%d", &n);
    int cache[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        numsSorted[i] = nums[i];
        used[i] = false;
    }
    sort(numsSorted, numsSorted + n);

    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            used[i] = true;
            if(numsSorted[i] == nums[i]) {
                height++;
                continue;
            }
            
            cache[0] = i;
            len = 1;
            
            while(1) {
                //printf("%");
                int find = binarySearchIndex(nums[cache[len-1]]);
                if(find == i) break;
                //printf("find = %d", find);
                //printf("%d", height);
				cache[len] = find;
                len ++;
                //printf("cache[%d] = %d\n", len[height], nums[i]);
                used[find] = true;
            }
            height++;
        }
    }
    printf("%d\n", height);
    
    for(int i = 0; i < n; i++){
    	used[i] = false;
	}
    //for(int i = 0; i < n; i++) printf("%d ", numsSorted[i]);
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            used[i] = true;
            if(numsSorted[i] == nums[i]) {
                cache[0] = i;
                len = 1;
                printf("1 %d\n", i+1);
                continue;
            }
            
            cache[0] = i;
            len = 1;
            
            while(1) {
                //printf("%");
                int find = binarySearchIndex(nums[cache[len-1]]);
                if(find == i) break;
                //printf("find = %d", find);
                //printf("%d", height);
				cache[len] = find;
                len ++;
                //printf("cache[%d] = %d\n", len[height], nums[i]);
                used[find] = true;
            }
            printf("%d ",len);
            for(int i = 0; i < len; i++){
            	printf("%d ", cache[i]+1);
			}
			printf("\n");
        }
    }
}