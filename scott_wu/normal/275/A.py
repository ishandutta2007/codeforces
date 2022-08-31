arr = [1,1,1,1,1]
grid = []
for i in range(5):
    grid.append (list(arr))
#grid = [arr,arr,arr,arr,arr]

xc = [0,1,-1,0,0]
yc = [0,0,0,1,-1]

for i in range (1, 4):
    arr = list (map (int, input().split()))
    for j in range (1, 4):
        #print (str(i) + ' ' + str(j) + ' ' + str(arr[j-1]))
        for k in range (arr[j-1]):
            for l in range (5):
                #print (grid[i+xc[l]][j+yc[l]])
                grid[i+xc[l]][j+yc[l]] = 1 - grid[i+xc[l]][j+yc[l]]
                #print (grid)

    #print (grid)

for i in range (1, 4):
    print (str(grid[i][1]) + str(grid[i][2]) + str(grid[i][3]))