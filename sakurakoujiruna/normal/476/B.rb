s1 = gets.chomp
s2 = gets.chomp

n = (s1.count('+') - s1.count('-') - (s2.count('+') - s2.count('-'))).abs
m = s2.count('?')

if (n - m).odd? or n > m
	puts 0
else
	n = (m - n) / 2
	ans = Math.gamma(m + 1) / Math.gamma(n + 1) / Math.gamma(m - n + 1) / (2 ** m)
	puts '%.12f' % ans
end