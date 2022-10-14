import sys
import collections

def solve():
    N = int(sys.stdin.readline().rstrip())
    A = list(map(int,sys.stdin.readline().rstrip().split()))
    q = collections.deque(A)
    ans = ''
    old = 0
    for i in range(N-1):
        l = q.popleft()
        r = q.pop()
        if l < r:
            if old < l:
                old = l
                ans += 'L'
                q.append(r)
            elif old < r:
                old = r
                ans += 'R'
                q.appendleft(l)
            else:
                break
        else:
            if old < r:
                old = r
                ans += 'R'
                q.appendleft(l)
            elif old < l:
                old = l
                ans += 'L'
                q.append(r)
            else:
                break
    else:
        r = q.pop()
        if old < r:
            old = r
            ans += 'R'
    print(len(ans))
    print(ans)

solve()