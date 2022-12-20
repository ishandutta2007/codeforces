def gint():
    return list(map(int, input().split()))
    

arr = list(map(lambda x:x**3, list(range(1, 10001))))

def check(x):
    p = len(arr)-1
    for y in arr:
        while p >= 0 and arr[p] + y > x:
            p -= 1
        if p < 0:
            break
        if arr[p] + y == x:
            return True
    return False

q, = gint()

for _ in range(q):
    x, = gint()
    print("YES" if check(x) else "NO")