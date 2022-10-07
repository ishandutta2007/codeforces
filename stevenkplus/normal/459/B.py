from collections import *
raw_input()
nums = map(int, raw_input().split())
d = defaultdict(int)
for n in nums:
  d[n] = d[n] + 1
print max(nums)-min(nums),  d[min(nums)] * d[max(nums)] if min(nums) != max(nums) else len(nums) * (len(nums) - 1) / 2