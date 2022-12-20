def gint():
    return list(map(int, input().split()))

for _ in range(int(input())):
    input()
    n, m = gint()
    inp = []
    for i in range(m):
        inp.append(gint())
    inp.sort(key=lambda e: e[0] + 2*e[1])
    
    def check(pos):
        if pos % 2 == 0:
            return sum(inp[pos])%2 != sum(inp[pos+1])%2
        else:
            return inp[pos][1] != inp[pos+1][1]
        
    if m % 2 != 0 or False in list(map(check, range(m-1))):
        print("NO")
    else:
        print("YES")