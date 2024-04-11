

t = int(input())

for T in range(t):
    n, m = map(int, input().split(" "))
    map_list = []
    for i in range(m):
        map_list.append({})
    for i in range(n):
        s = input()
        for j in range(m):
            if s[j] in map_list[j]:
                map_list[j][s[j]]+=1
            else:
                map_list[j][s[j]] = 1
    for i in range(n-1):
        s = input()
        for j in range(m):
            map_list[j][s[j]]-=1

    res = ""
    for i in range(m):
        for c in map_list[i].keys():
            if map_list[i][c] == 1:
                res = res+c
    print(res)