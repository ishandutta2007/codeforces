MP = lambda a, b : list(map(a, b))

def gint():
    return MP(int, input().split())

q, = gint()
        
for _ in range(q):
    n, = gint()
    inp = gint()
    def solve(arr, h = 0):
        if len(arr) == 0:
            return []
        pos = arr.index(max(arr))
        return solve(arr[:pos], h+1) + [h] + solve(arr[pos+1:], h+1)
    print(' '.join(MP(str, solve(inp))))