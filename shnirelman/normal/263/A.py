a = []
for i in range(5):
    a.append(input().split())
    
for i in range(5):
    for j in range(5):
        if(a[i][j] == '1'):
            print(abs(i - 2) + abs(j - 2))