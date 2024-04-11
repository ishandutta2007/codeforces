#!/usr/bin/env ruby

n = gets.to_i

l, r = 0, n
while l != r
  m = (l + r + 1) / 2
  need = 3 * m * (m + 1) / 2 - m
  if need <= n
    l = m
  else
    r = m - 1
  end
end

l -= 1 while l > 0 && [0, 2, 1][l % 3] != n % 3
puts (l + 2) / 3