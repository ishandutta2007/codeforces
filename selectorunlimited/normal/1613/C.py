import math
import sys
from collections import defaultdict, Counter
from functools import lru_cache

t = int(input())
for _ in range(t):
    n, h = [int(i) for i in input().split()]
    arr = [int(i) for i in input().split()]
    
    def check(k):
        s = 0
        j = 0
        while j < n:
            l = arr[j]
            r = arr[j] + k - 1
            j += 1
            while j < n and arr[j] <= r:
                r = arr[j] + k - 1
                j += 1
            s += (r - l + 1)
        return s >= h
    
    low = 1
    high = int(1e18)
    while low <= high:
        mid = (low + high ) // 2
        if check(mid):
            high = mid - 1
        else:
            low = mid + 1
    print(low)